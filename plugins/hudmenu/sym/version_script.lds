{
    global:
        Plugify_*;

        /* s2sdk binding slots (defined by s2sdk_bindings, filled by the plugify module) */
        __s2sdk_*;

        /* polyhook binding slots (defined by polyhook_bindings, filled by the plugify module
           from the polyhook plugin's exported methods) */
        __polyhook_*;

        /* permissions binding slots (defined by permissions_bindings, filled by the plugify
           module from the permissions plugin's exported methods) */
        __permissions_*;

        /* Exported methods (hudmenu.pplugin -> sdk/include/hudmenu). pisexcompat resolves every
           displayed menu through GetClientMenuType; keep this list in sync with the manifest. */
        GetClientMenuType;
        SetClientMenuType;

    local: *;
};
