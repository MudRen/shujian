#include <ansi.h>

inherit ITEM;

string get_long();

void create()
{
        set_name( "��ǩ", ({ "zhu qian", "qian"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", (:get_long:));
                set("value", 0);
                set("material", "wood");
        }
        setup();
}

string get_long()
{
        string long;
        mapping qianwen;

        qianwen = query("qianwen");

        if (!mapp(qianwen) || query("owner") != this_player()->query("id"))
                return "һ����������ǩ����������ɰ��������С�֣�����̫���С�\n";

        long = "һ����������ǩ���������˼���С�֣�\n";
        long += "                "+HIW +"��"+ qianwen["title"] + "��\n" + NOR;
        long += HIM + qianwen["doc"] + "\n" + NOR;
        return long;
}

void csh_qianwen()
{
        set("qianwen","/d/city/npc/qianwen/qianwen"->get_qian());
        set("long",(:get_long:));
        return;
}

