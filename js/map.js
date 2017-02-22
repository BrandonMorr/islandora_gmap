(function ($) {
  Drupal.islandora_gmap = {
    maps: {},
    init: function () {
      $.each(Drupal.settings.islandora_gmap.data, Drupal.islandora_gmap.initMap);
    },
    initMap: function (id, info) {
      var map = new google.maps.Map(document.getElementById(id), {
        center: {lat: 0, lng: 0},
        zoom: info.zoom
      });
      Drupal.islandora_gmap.maps[id] = map;

      map.data.addGeoJson(info.geojson);
      Drupal.islandora_gmap.recenterMap(map);
    },
    recenterMap: function (map, zoom) {
      var bounds = new google.maps.LatLngBounds();

      map.data.forEach(function (feature) {
        feature.getGeometry().forEachLatLng(function (latlng) {
          bounds.extend(latlng);
        });
      });

      map.fitBounds(bounds);
    }
  };
})(jQuery);
