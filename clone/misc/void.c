// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

void create()
{
	set("short","�����԰");
	set("long",@LONG	
������Ǵ�˵�е� VOID -- �������ʦ�������԰. �㿴������һƬ
��ãã��, ��һ���������ð��һֻ���, �ݸ���һ�ޡ��ɿڿ��֡�(tm), 
Ȼ��վ��һ�Ժ�а���Ц��. �ֹ���һ��, һֻ���������˹���, һ���ı�
����ֻ��첢��������������ƿ����, ��Ц������ʹ�����ǰ��ʧ��.
��ҡҡͷ, ���ֵط����ǲ�Ҫ��̫�õĺ�.
LONG
	);

	set("item_desc/down", "����һ����ɲ�ĺڶ�����һ����ȥ��Ҫ�۳��ٷ�֮��ʮ�ľ��顣\n");
	set("no_fight", 1);
	set("no_sleep_room", 1);
	set("no_update", 1);
	set("exits", ([
                "down":"/d/city/xiaochidian",
	]));

	setup();
}

void init()
{
	add_action("do_action", "");
}

int do_action(string arg)
{
	string action = query_verb();

	switch (action) {
		case "exercise":
		case "practice":
        	case "study":
        	case "respirate":
			write("�ⲻ�����������ĵط���\n");
			return 1;
	}
	return 0;
}
