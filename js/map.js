(function ($) {
  Drupal.islandora_gmap = {
    maps: {},
    init: function () {
      $.each(Drupal.settings.islandora_gmap.data, function (id, info) {
        var $map = $("#" + id);
        $map.once('islandora-gmap-init', function () {
          var $collapsed_fieldsets = $map.closest('fieldset.collapsible.collapsed');
          if ($collapsed_fieldsets.length > 0) {
            $collapsed_fieldsets.one('collapsed', function (evt) {
              Drupal.islandora_gmap.initMap(id, info);
            });
          }
          else {
            Drupal.islandora_gmap.initMap(id, info);
          }
        });
      });
    },
    initMap: function (id, info) {
      var $map = $("#" + id);
      var map = new google.maps.Map($map.get(0), info.map_settings);
      Drupal.islandora_gmap.maps[id] = map;

      map.data.addGeoJson(info.geojson);
      Drupal.islandora_gmap.recenterMap(map, info);
    },
    recenterMap: function (map, info) {
      var bounds = new google.maps.LatLngBounds();

      map.data.forEach(function (feature) {
        feature.getGeometry().forEachLatLng(function (latlng) {
          bounds.extend(latlng);
        });
      });

      if (info.fit) {
        map.fitBounds(bounds);
      }
      else {
        map.panTo(bounds.getCenter());
      }
    }
  };
})(jQuery);
