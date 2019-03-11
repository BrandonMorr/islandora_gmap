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

      if (info.cluster_points) {
        var markerClusterer = new MarkerClusterer(map, null, {imagePath:
          Drupal.settings.basePath+'sites/all/libraries/markerclusterer/images/m'
        });
      }

      info.bounds = new google.maps.LatLngBounds();

      if (info.show_point_info) {
        var boxText = document.createElement("div");
        var infoWindow = new google.maps.InfoWindow({
          content: boxText
        });
      }

      map.data.addListener('addfeature', function (f_evt) {
        f_evt.feature.getGeometry().forEachLatLng(function (latlng) {
          info.bounds.extend(latlng);
        });
        var marker = new google.maps.Marker({
          position: f_evt.feature.getGeometry().get(),
          title: f_evt.feature.getProperty('name'),
          map: map
        });

        if (info.cluster_points) {
          markerClusterer.addMarker(marker);
        }

        if (info.show_point_info) {
          google.maps.event.addListener(marker, 'click', function (marker, f_evt) {
            return function() {
              boxText.innerHTML = info.infobox_html;
              infoWindow.open(map, marker);
            };
          }(marker, f_evt));
        }

        Drupal.islandora_gmap.recenterMap(map, info);
      });

      if (info.geojson != null) {
        map.data.addGeoJson(info.geojson);
        map.data.setMap(null);
      }

      $.each(info.kml, function (kid, url) {
        var layer = new google.maps.KmlLayer({
          preserveViewport: true,
          map: map,
          url: url
        });
        var listener = layer.addListener('defaultviewport_changed', function () {
          info.bounds.union(layer.getDefaultViewport());
          Drupal.islandora_gmap.recenterMap(map, info);
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
