# Islandora Google Maps

## Introduction

Facilitates the rendering of maps using the Google Maps JS API, v3.

This module does not do anything on its own, but defines multiple hooks which modules might implement to provide GeoJSON data or KML documents to be rendered on a map. There are a couple of submodules implementing these hooks which may be of interest:

* [scrape_mods_to_gmap](https://github.com/discoverygarden/islandora_gmap/tree/7.x/modules/scrape_mods_to_gmap), to scrape data from MODS datastreams
* [kml_datastream_scrape](https://github.com/discoverygarden/islandora_gmap/tree/7.x/modules/kml_datastream_scrape), to scrape accessible KML datastreams to be rendered

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

At `admin/islandora/tools/gmaps`, there is one point of required configuration: The "Google API Key", under "Basic Configuration". There are some other configuration which controls the dimensions of the map, constrains the allowed zoom levels, and adjusts the initial viewport configuration.

## Troubleshooting/Issues

Having problems or solved a problem? Contact [discoverygarden](http://support.discoverygarden.ca).

## Maintainers/Sponsors

Current maintainers:

* [discoverygarden](http://www.discoverygarden.ca)

## Development

If you would like to contribute to this module, please check out our helpful
[Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers)
info, [Developers](http://islandora.ca/developers) section on Islandora.ca and
contact [discoverygarden](http://support.discoverygarden.ca).

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
