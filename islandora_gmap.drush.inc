<?php

/**
 * @file
 * Drush integration for islandora_gmap.
 */
const JS_UTILITY_DOWNLOAD_URI = 'https://github.com/googlemaps/v3-utility-library/archive/master.zip';
const MARKERCLUSTERER_ORIGINAL_DIR = 'markerclusterer';

/**
 * Implements hook_drush_command().
 */
function islandora_gmap_drush_command() {
  $items['markerclusterer-plugin'] = array(
    'callback' => 'drush_gmap_markerclusterer_plugin',
    'description' => dt('Download and install the Google Maps marker clusterer plugin.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'aliases' => array('markerclustererplugin'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function islandora_gmap_drush_help($section) {
  switch ($section) {
    case 'drush:markerclusterer-plugin':
      return dt('Download and install the Google Maps marker clusterer plugin, default location is sites/all/libraries.');
  }
}

/**
 * Command to download the markerclusterer plugin.
 */
function drush_gmap_markerclusterer_plugin() {
  $path = _drush_core_directory("@site:sites/all/libraries");

  // Create the libraries path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive.
  // TODO figure out dir stuff
  if ($filepath = drush_download_file(JS_UTILITY_DOWNLOAD_URI)) {
    $filename = basename($filepath);

    // Decompress the zip archive into the cwd.
    drush_tarball_extract($filename);

    // Remove any existing markerclusterer plugin directory.
    $dirname = MARKERCLUSTERER_ORIGINAL_DIR;
    $pathdir = $path . '/' . $dirname;
    if (is_dir($dirname) || is_dir('markerclusterer')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('markerclusterer', TRUE);
      drush_log(dt('An existing markerclusterer plugin was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Move the cluster library and unlink the rest of the v3-utils.
    rename('v3-utility-library-master/markerclusterer', 'markerclusterer');
    file_unmanaged_delete_recursive('v3-utility-library-master');
  }

  if (is_dir($dirname)) {
    drush_log(dt('Marker clusterer plugin has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the marker clusterer plugin to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
