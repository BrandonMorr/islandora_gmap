<?php

/**
 * @file
 * Admin form and friends.
 */

/**
 * Admin settings form.
 */
function islandora_gmap_admin_form($form, &$form_state) {
  $form['#tree'] = FALSE;

  $form['sets'] = array(
    '#type' => 'vertical_tabs',
  );

  foreach (module_implements('islandora_gmap_form_fieldset') as $module) {
    $hook_func = "{$module}_islandora_gmap_form_fieldset";
    $form['sets'][$module] = $hook_func($form_state);
  }

  return system_settings_form($form);
}
