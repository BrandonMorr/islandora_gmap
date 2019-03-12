<?php

/**
 * Implements template_preprocess_HOOK().
 *
 * Default template: islandora-gmap-infobox.tpl.php.
 *
 * @param array $variables
 *   An associative array containing:
 *   - islandora_object: An AbstractObject from islandora.
 */
function template_preprocess_islandora_gmap_infobox(&$variables) {
  $islandora_object = $variables['islandora_object'];

  $label = $islandora_object->label;
  $variables['islandora_gmap_infobox_title'] = "<h5>$label</h5>";

  $pid = $islandora_object->id;
  $variables['islandora_gmap_infobox_body'] = "<p><a href=\"/islandora/object/$pid\">$pid</a></p>";
}
