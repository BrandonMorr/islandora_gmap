# Scrape KML datastreams for Google Maps

## Introduction

Support the use of KML datastreams in Google Maps.

## Requirements

This module requires the following modules/libraries:

* [Islandora Google Maps](https://github.com/discoverygarden/islandora_gmap)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

In the admin form at `admin/islandora/tools/gmaps` in the "KML Datastreams" tab, the criteria to match datastreams can be modified; by default, we look for any datastream with the `application/vnd.google-earth.kml+xml` MIME-type.

If desired, matching may be additionally constrained to particular datastream identifiers and/or on objects of particular content models.

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
