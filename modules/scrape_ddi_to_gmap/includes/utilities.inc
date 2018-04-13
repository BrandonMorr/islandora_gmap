<?php
/**
 * @file
 * Helper functions.
 */

/**
 * Helper to parse textarea variable values to arrays.
 *
 * @param string $paths
 *   A string of XPaths separated with Windows line endings, as provided by
 *   textareas.
 *
 * @return string[]
 *   An array of XPaths, as strings.
 */
function _scrape_ddi_to_gmap_parse_paths($paths) {
  return array_filter(array_map('trim', explode("\r\n", $paths)));
}

/**
 * Helper to perform the XPath queries.
 *
 * @param AbstractObject $object
 *   The object from which to scrape the DDI.
 * @param array $xpaths
 *   The array of XPaths to run, as strings.
 *
 * @return DOMNode[]
 *   An array of DOMNode instances resulting from the XPath queries.
 */
function _scrape_ddi_to_gmap_scrape(AbstractObject $object, array $xpaths) {
  if (!isset($object['DDI'])) {
    return array();
  }

  $doc = new DOMDocument();
  $doc->loadXML($object['DDI']->content);
  $xpath = new DOMXPath($doc);

  return call_user_func_array('array_merge', array_map('iterator_to_array', array_map(array($xpath, 'query'), $xpaths)));
}

/**
 * Callback helper to actually parse the configured XPaths.
 *
 * @param AbstractDatastream $datastream
 *   The datastream from which to scrape elements.
 *
 * @return DOMNode[]
 *   An array of DOMNode instances, scraped from the datastream.
 */
function _scrape_ddi_to_gmap_get_kml_elements(AbstractDatastream $datastream) {
  $xpaths = _scrape_ddi_to_gmap_parse_paths(variable_get('scrape_ddi_to_gmap_kml_xpaths', SCRAPE_DDI_TO_GMAP_KML_XPATHS));
  return _scrape_ddi_to_gmap_scrape($datastream->parent, $xpaths);
}
