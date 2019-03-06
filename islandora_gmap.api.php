<?php
/**
 * @file
 * Hook documentation.
 */

/**
 * Build out a fieldset of configuration for your module.
 *
 * @param array $form_state
 *   A reference to the form state being used to render the admin form.
 *
 * @return array
 *   An associative array containing a fieldset. Non-property keys (indicating
 *   child elements) will be used to create variables... These variables should
 *   be uninstalled in the modules creating them.
 */
function hook_islandora_gmap_form_fieldset(&$form_state) {
  $base = array(
    '#type' => 'fieldset',
    '#title' => t('My awesome config'),
  );

  $base['my_module_value_one'] = array(
    '#type' => 'textfield',
    '#title' => t('Value the first'),
    '#default_value' => variable_get('my_module_value_one', 1),
  );

  $base['my_module_value_two'] = array(
    '#type' => 'textfield',
    '#title' => t('Value the second'),
    '#default_value' => variable_get('my_module_value_two', 2),
  );

  return $base;
}

/**
 * Gather GeoJSON Feature objects for rendering on a map for the given object.
 *
 * Can optionally return a `properties` array in the geojson feature with
 * 'label', 'pid' and 'description' keys; these will be used in infobox
 * windows if `islandora_gmap_show_point_info` is turned on.
 *
 * @param AbstractObject $object
 *   The object for which to gather GeoJSON Features.
 *
 * @return array
 *   An array of GeoJSON Features.
 *
 * @see http://geojson.org/geojson-spec.html#feature-objects
 */
function hook_islandora_gmap_gather_geojson(AbstractObject $object) {
  $geojson = array();

  $geojson[] = array(
    'type' => 'Feature',
    'geometry' => array(
      'type' => 'Point',
      'coordinates' => array(
        -63.1245071,
        46.2350236,
      ),
    ),
    'properties' => array(
      'label' => 'My Object Label',
      'pid' => 'my:coolpid',
      'description' => 'Sweet object description.',
    ),
  );

  return $geojson;
}

/**
 * Permit altering of GeoJSON hook values.
 *
 * @param array $geojson
 *   A reference to the array of GeoJSON features gathered.
 * @param AbstractObject $object
 *   The object for which GeoJSON is being gathered.
 *
 * @see hook_islandora_gmap_gather_geojson()
 */
function hook_islandora_gmap_gather_geojson_alter(array &$geojson, AbstractObject $object) {
}

/**
 * Gather KML documents to render on a map.
 *
 * @param AbstractObject $object
 *   The object for which the KML is to be gathered.
 *
 * @return array
 *   An array of URLs pointing at publically-accessible KML documents.
 */
function hook_islandora_gmap_gather_kml(AbstractObject $object) {
  return array(
    'http://googlemaps.github.io/kml-samples/kml/Placemark/placemark.kml',
  );
}
