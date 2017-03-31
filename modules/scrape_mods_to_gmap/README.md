# Google Maps: Scrape MODS

## Introduction

Scrapes some coordinates from MODS, in much the same manner as [mjordan](islandora_solr_metadata_description)'s [islandora_simple_map](https://github.com/mjordan/islandora_simple_map) module.

## Requirements

This module requires the following modules/libraries:

* [Islandora Google Maps](https://github.com/discoverygarden/islandora_gmap)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

"Coordinate XPaths" from which to scrape can be configured, one per line. By default, they should contain only coordinate data as pairs of signed floating point numbers separated by a comma, each indicating latitude and longitude in degrees.

"KML XPaths" allows for KML documents embedded inside MODS documents to be extracted for use in Google Maps.

The "attempt cleanup" option presently permits a semi-colon instead of a comma to be used (legacy functionality, mirroring islandora_simple_map).

The "fallback to search" option will forward anything which does not appear to be coordinate data off as a query against the [Google Places API](https://developers.google.com/places/web-service/search#TextSearchRequests); off by default to avoid the associated increased (10-times normal) API quota usage.

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
