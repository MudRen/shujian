//Yanqi 08/10/2k

inherit ITEM;

void create()
{
        set_name("��ʯ", ({ "ju shi", "shi kuai", "shi" }) );
        set_weight(30000);
        set("unit", "��");
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long", "����һ���ʯ��\n");
        set("no_drop",1);
        set("no_get",1);
        set("no_give",1);
	}
	setup();
}
