<?php
/**
 * @file
 * Utility functions/
 */

/**
 * Helper to invoke hooks to gather GeoJSON info for a given object.
 *
 * @param AbstractObject $object
 *   The object for which to gather GeoJSON features.
 *
 * @return array|NULL
 *   If any features were returned, an associative array wrapping them up in a
 *   "FeatureCollection"; otherwise, NULL.
 */
function islandora_gmap_gather_geojson(AbstractObject $object) {
  $geojson = module_invoke_all('islandora_gmap_gather_geojson', $object);
  drupal_alter('islandora_gmap_gather_geojson', $geojson, $object);

  if ($geojson) {
    return array(
      'type' => 'FeatureCollection',
      'features' => $geojson,
    );
  }
}

/**
 * Helper to invoke hooks to gather KML info for a given object.
 *
 * @param AbstractObject $object
 *   The object for which to gather KML.
 *
 * @return array
 *   An array of KML info.
 */
function islandora_gmap_gather_kml(AbstractObject $object) {
  $kml = module_invoke_all('islandora_gmap_gather_kml', $object);
  drupal_alter('islandora_gmap_gather_kml', $kml, $object);
  return $kml;
}
