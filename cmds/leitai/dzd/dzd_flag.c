
inherit ITEM;

int do_check(string arg);

void create()
{
set_name("������",({"dzd's flag","wakakak"}));
set_weight(1);
        if(clonep())
                set_default_object(__FILE__);
        else {
        set("invisibility",1);
        set("no_drop",1);
        set("no_give",1);
        set("no_get",1);
        }
        setup();
}

void init()
{
add_action("do_check",({"chakan"}));
}
