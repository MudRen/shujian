
inherit F_BOAT;

void create()
{
	set_name("�󺣴�", ({ "boat" }));
	set("short", "�󺣴�");
	set_weight(2000000);
	set_max_encumbrance(1400000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("long", "����һ���󷫴����׷�����ʮ���ɸߵ�˫Φ�ϣ���ʻ�ٶ��Ŀ졣������
����ھ��κ�����Ҳ����������λֻ꣬�����Ʈ���������������һ��
������书�͸����ĺ������죬�ſ��ڴ�����ʻ���Ӵ󺣴��Ĵ���������
��(lookout)�����Թ��͵������ϵķ羰���������б�������֪(sign)��\n");
		set("outdoors", "��");
		set("location", 1);
		set("item_desc", ([
			"sign" : "\n�ϴ��밶(start)�Ժ󣬲���(turn)�������У����ҿ��Բ�ʱͣ����(stop)��\n"+
				"ǧ�������Я�����̣���Ȼ�����ʧ��ãã��֮�С�\n\n",
		]));
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
