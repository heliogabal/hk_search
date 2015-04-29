<?php
/**
 * @file
 * hk_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hk_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "ds_extras" && $api == "ds_extras") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hk_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function hk_search_default_search_api_index() {
  $items = array();
  $items['solr_node_index'] = entity_import('search_api_index', '{
    "name" : "Solr Node Index",
    "machine_name" : "solr_node_index",
    "description" : null,
    "server" : "db_search",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_apart_bathrooms" : { "type" : "integer" },
        "field_apart_floor" : { "type" : "text" },
        "field_apart_hoa_fee" : { "type" : "decimal" },
        "field_apart_living_space" : { "type" : "decimal" },
        "field_apart_no" : { "type" : "text" },
        "field_apart_price" : { "type" : "decimal" },
        "field_apart_rooms" : { "type" : "integer" },
        "field_ausstattung" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_heating_type" : { "type" : "string" },
        "field_kategorie" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_object_ref" : { "type" : "integer", "entity_type" : "node" },
        "field_object_ref:body:value" : { "type" : "text" },
        "field_object_ref:field_address:thoroughfare" : { "type" : "text" },
        "field_object_ref:field_bezirk" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_object_ref:field_kategorie" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_object_ref:field_object_images:file" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "file" },
        "field_object_ref:field_object_images:file:fid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_object_ref:field_object_images:file:field_file_image_alt_text" : { "type" : "list\\u003Ctext\\u003E" },
        "field_object_ref:field_object_images:file:field_file_image_title_text" : { "type" : "list\\u003Ctext\\u003E" },
        "field_object_ref:field_object_images:file:mime" : { "type" : "list\\u003Ctext\\u003E" },
        "field_object_ref:field_object_images:file:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_object_ref:field_object_images:file:size" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_object_ref:field_object_images:file:type" : { "type" : "list\\u003Cstring\\u003E" },
        "field_object_ref:field_object_images:file:url" : { "type" : "list\\u003Ctext\\u003E" },
        "field_object_ref:field_objekt_wkt:latlon" : { "type" : "text" },
        "field_object_ref:field_objektid_nunumeric" : { "type" : "text" },
        "field_object_ref:status" : { "type" : "integer" },
        "field_object_ref:title_field" : { "type" : "text" },
        "field_objekt_wkt:latlon" : { "type" : "text" },
        "is_new" : { "type" : "boolean" },
        "language" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_ranges_alter" : { "status" : 0, "weight" : "-50", "settings" : { "fields" : [] } },
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "objekt" : "objekt", "apartment" : "apartment" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "language", "languages" : { "de" : "de", "en" : "en" } }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "field_apart_floor" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function hk_search_default_search_api_server() {
  $items = array();
  $items['db_search'] = entity_import('search_api_server', '{
    "name" : "DB Search",
    "machine_name" : "db_search",
    "description" : "Test Server to be replaced by SOLR afterwards",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 0,
      "autocomplete" : { "suggest_suffix" : 1, "suggest_words" : 1 },
      "indexes" : {
        "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          }
        },
        "solr_node_index" : {
          "is_new" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "is_new",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "language" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_apart_bathrooms" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_apart_bathrooms",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_apart_floor" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_apart_hoa_fee" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_apart_hoa_fee",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_apart_living_space" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_apart_living_space",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_apart_no" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_apart_price" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_apart_price",
            "type" : "decimal",
            "boost" : "1.0"
          },
          "field_apart_rooms" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_apart_rooms",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_object_ref" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_object_ref",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_ausstattung" : {
            "table" : "search_api_db_solr_node_index_field_ausstattung",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_kategorie" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_kategorie",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_heating_type" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_heating_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_object_ref:status" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_object_ref_status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_object_ref:title_field" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_object_ref:field_kategorie" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_object_ref_field_kategorie",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_object_ref:field_objektid_nunumeric" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_object_ref:field_bezirk" : {
            "table" : "search_api_db_solr_node_index",
            "column" : "field_object_ref_field_bezirk",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_objekt_wkt:latlon" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_object_ref:body:value" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_object_ref:field_objekt_wkt:latlon" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file" : {
            "table" : "search_api_db_solr_node_index_field_object_ref_field_object_im",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_address:thoroughfare" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:fid" : {
            "table" : "search_api_db_solr_node_index_field_object_ref_field_object__1",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:name" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:mime" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:size" : {
            "table" : "search_api_db_solr_node_index_field_object_ref_field_object__2",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:url" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:type" : {
            "table" : "search_api_db_solr_node_index_field_object_ref_field_object__3",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:field_file_image_alt_text" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_object_ref:field_object_images:file:field_file_image_title_text" : {
            "table" : "search_api_db_solr_node_index_text",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids_form" : [],
      "clean_ids" : false,
      "site_hash_form" : [],
      "site_hash" : false,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8099",
      "path" : "\\/solr\\/d41d8cd98f00b204e9800998ecf8427e.hk.new.drupalforgood.eu.o5571260507",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1"
  }');
  return $items;
}
