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

      info.bounds = new google.maps.LatLngBounds();

      map.data.addListener('addfeature', function (f_evt) {
        f_evt.feature.getGeometry().forEachLatLng(function (latlng) {
          info.bounds.extend(latlng);
        });
        Drupal.islandora_gmap.recenterMap(map, info);
      });

      if (info.geojson != null) {
        map.data.addGeoJson(info.geojson);
      }

      var layers = [];
      $.each(info.kml, function (kid, url) {
        var layer = new google.maps.KmlLayer({
          preserveViewport: true,
          map: map,
          url: url
        });
        var listener = layer.addListener('status_changed', function () {
          //layer.removeListener(listener);
          var status = layer.getStatus();
          if (layer.getStatus() == google.maps.KmlLayerStatus.OK) {
            info.bounds.extend(this.getDefaultViewport());
            Drupal.islandora_gmap.recenterMap(map, info);
          }
        });
      });
    },
    recenterMap: function (map, info) {
      var bounds = info.bounds;
      if (info.fit) {
        map.fitBounds(bounds);
      }
      else {
        map.panTo(bounds.getCenter());
      }
    }
  };
})(jQuery);
