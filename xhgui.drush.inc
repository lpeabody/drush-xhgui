<?php
/**
 * Implements hook_drush_help_alter().
 */
function xhgui_drush_help_alter(&$command) {
  if ($command['command'] == 'global-options') {
    // Do not include these in options in standard help.
    $command['options']['xhgui'] = array(
      'description' => 'Enable XHProf profiling via XHGui.',
    );
    $command['sub-options']['xhgui']['xhgui-header'] = 'Absolute path to XHGui\'s header.php file.';
  }
}

function xhgui_drush_init() {
  if (xhgui_enabled()) {
    $header = drush_get_option('xhgui-header', FALSE);
    require_once $header;
  }
}

function xhgui_enabled() {
  if (drush_get_option('xhgui')) {
    $header = drush_get_option('xhgui-header', FALSE);
    if (!extension_loaded('xhprof')) {
      return drush_set_error('You must enable the xhprof PHP extension in your CLI PHP in order to profile.');
    }
    if (!file_exists($header)) {
      return drush_set_error('You must specify the path to XHGui\'s header.php in the xhgui-header Drush option.');
    }
    return TRUE;
  }
}
