
inherit F_BOAT;

void create()
{
        set_name("С����", ({ "boat" }));
        set("short", "С����");
        set_weight(1000000);
        set_max_encumbrance(700000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "����һ����ª�����Ʒ�������������ȫ������ľ���ɡ�����ʱ���Կ���(lookout)
һ���ŵķ��˴Ӵ󺣴�����ʹ֮��ס�ص�����\n");
                set("value", 50);
                set("location", 1);
                set("outdoors", "��");
        }
        setup();
}

int is_container() { return 1; }

void init()
{
   add_action("do_turn","turn");
   add_action("do_out","out");
   add_action("do_start","start");
   add_action("lookout","lookout");
   add_action("do_stop","stop");
}
