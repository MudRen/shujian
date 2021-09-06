// Room: /d/city/zhubaodian.c

#define KICK_TO	__DIR__"xidajie1"

inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "�鱦��");
	set("long", @LONG
����һ��װ�κ������鱦�ꡣ���ڰ����˸��ֽ���������������ӳ�ý��
�Ի͡���������ģ���������ڵ�ͷ��ϸ�������ţ��ϰ��ڲ����䷳�������š�
LONG
	);

	set("exits", ([
		"north" : __DIR__"xidajie1",
	]));

        set("objects", ([
		__DIR__"npc/zhu" : 1,
        ]));
        set("no_clean_up", 0);

	set("coor/x",80);
  set("coor/y",-10);
   set("coor/z",0);
   set("coor/x",80);
  set("coor/y",-10);
   set("coor/z",0);
   setup();
	quarter_pass();
}

void kick_all()
{
	object *ob;
    int i;

	tell_room(this_object(), "�ϰ忴�˿���ɫ������˵�������ûؼ�������\n", ({}));
	ob = all_inventory(this_object());
	for(i = 0; i < sizeof(ob); i++) {
		if (userp(ob[i])) {
			if (!living(ob[i])) message_vision("�ϰ��$N�ӳ����鱦�ꡣ\n", ob[i]);
			else message_vision("�����ϰ�Ļ���$Nֻ���߳����鱦�ꡣ\n", ob[i]);
			ob[i]->move(KICK_TO);
			if (!living(ob[i])) tell_room(KICK_TO, ob[i]->name() + "���ӳ����鱦�ꡣ\n", ({ob[i]}));
			else tell_room(KICK_TO, ob[i]->name() + "���鱦����������������˳�����\n", ({ob[i]}));
		}
	}
}

void quarter_pass()
{
	mixed *local;
// object *ob;
// int i,paytime;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) kick_all();
	call_out("quarter_pass", 30);
}

