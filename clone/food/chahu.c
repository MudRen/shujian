inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("���", ({ "cha hu", "hu" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ����ɫ�Ĵɲ����\n"
);
                set("unit", "��");
                set("value", 80);
                set("max_liquid", 40);
        }

        set("liquid", ([
                "type": "water",
                "name": "��ˮ",
                "remaining": 40,
        ]) );
}

