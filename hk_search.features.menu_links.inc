<?php
/**
 * @file
 * hk_search.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function hk_search_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_buy:buy
  $menu_links['main-menu_buy:buy'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'buy',
    'router_path' => 'buy',
    'link_title' => 'Buy',
    'options' => array(
      'icon' => array(
        'icon' => '',
        'position' => 'title_before',
        'title_wrapper_element' => 'span',
        'title_wrapper_class' => 'title',
        'breadcrumb' => 0,
        'title_wrapper' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_buy:buy',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_rent:rent
  $menu_links['main-menu_rent:rent'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'rent',
    'router_path' => 'rent',
    'link_title' => 'Rent',
    'options' => array(
      'icon' => array(
        'icon' => '',
        'position' => 'title_before',
        'title_wrapper_element' => 'span',
        'title_wrapper_class' => 'title',
        'breadcrumb' => 0,
        'title_wrapper' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_rent:rent',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Buy');
  t('Rent');


  return $menu_links;
}