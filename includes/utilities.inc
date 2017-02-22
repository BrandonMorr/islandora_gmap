<?php
/**
 * @file
 * Utility functions/
 */

/**
 * Helper to invoke hooks to gather GeoJSON info for a given object.
 */
function islandora_gmap_gather_geojson(AbstractObject $object) {
  $geojson = module_invoke_all('islandora_gmap_gather_geojson', $object);
  drupal_alter('islandora_gmap_gather_geojson', $geojson, $object);
  return $geojson;
}
