// Room: /d/city/yanju.c

inherit ROOM;

#define AGE_LIMIT 22
#define LIME "/d/city/obj/lime"
#define DAI "/d/city/obj/budai"

void create()
{
	set("short", "�����ξ�");
	set("long", @LONG
������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ�
���Ͻ���Ʈ�����������д�š������ξ֡��ĸ����֣������������˵��Ǹ�
���Ƿ�������һ���ǽ������εļ�ɢ֮�أ��ٸ�Ϊ�˱��ڹ���, ������˰, ��
���������ξ�, ֱ�������ڳ�͢����ڴ���һ��������˵Ц��ǽ�Ƕ���һ��ʯ
�ҷۣ��Ա߷��Ÿ�������
LONG
	);

	set("exits", ([
		"west" : __DIR__"nandajie2",
        "east" : __DIR__"dongting2",
	]));

	set("objects", ([
	        __DIR__"npc/shisong" : 1,
	        __DIR__"npc/yanshang" : 2,
	]));
	
	set("hui",5);
	set("dai",2);

	set("coor/x",110);
  set("coor/y",-30);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",-30);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",-30);
   set("coor/z",0);
   set("coor/x",110);
  set("coor/y",-30);
   set("coor/z",0);
   set("incity",1);
	setup();
}

void init()
{
	add_action("do_na","na");
    add_action("do_zhua",({"zhua","zhuaqu"}));
}

int do_zhua(string arg)
{
	object me = this_player();
	object ob, ob1;
	
	if (!arg || arg != "ʯ��")
		return 0;
	if (!(ob = present("bu dai", me)))
		return notify_fail("������ʯ�ң��㲻�������۾�����\n");
	if (me->query_temp("zhua_shihui"))
		return notify_fail("��ץ��ʯ�ң�С���ξֵ��˴��㣡\n");
	if (!ob->query("fill_lime"))
		return notify_fail("��������ڴ�����ʵ������װ����ʯ�ҡ�\n");
	if (query("hui") < 1)
		return notify_fail("�˼ҸǷ�����Ҫ��ʯ���أ���͵������ô�죿��\n");
	if (me->query("age") >= AGE_LIMIT)
		return notify_fail("�㶼��ô�����ˣ���ѧС��ץʯ�ң���\n");
	if (random(me->query_kar()) < 15)
		return notify_fail("ͻȻ��һ�����ɿ�������Ķ����������Ⱥ��ţ�������͵ʯ�ң�����\n");
	message_vision("$N���˲�ע�⣬͵͵�ӵ���ץ��һ��ʯ�ҷ������ϵĴ����\n", me);
	ob1 = new(LIME);
	ob1->move(ob);
	add("hui",-1);
	me->set_temp("zhua_shihui",1);
	call_out("do_can_zhua", 50, me);
	return 1;
}

void do_can_zhua(object me)
{
	if (!me) return;
	me->delete_temp("zhua_shihui");
}

int do_na(string arg)
{
	object me = this_player();
	object ob;
	string msg;

	if (!arg || arg != "����")
		return 0;
/*
	if (query("dai") < 1)
		return notify_fail("�˼�װʯ����Ҫ�ò����أ���͵������ô�죿��\n");
*/
// ����������� by daidai
       if (me->query_temp("quest/�廢���ŵ�/����"))
          return notify_fail("�������Ѿ����˲����ˣ��˼�װʯ����Ҫ�ò����أ���͵������ô�죿��\n");
	if (me->query("age") >= AGE_LIMIT)
		return notify_fail("�㶼��ô�����ˣ���͵͵�ñ��˶�������\n");
	if (random(me->query_kar()) < 15)
		return notify_fail("ͻȻ��һ�����ɿ�������Ķ����������Ⱥ��ţ�������͵���ӣ�����\n");

	msg = "$N�ýŲ��˲����ϵĲ�����˳�ּ�������";
	if (ob = present("bu dai", me)) {
		msg += "�����Լ����ϵ��Ʋ���������һ�ԡ�\n";
		destruct(ob);
	}
	else
        msg += "��\n";
	message_vision(msg, me);
	ob = new(DAI);
	ob->move(me);
    me->set_temp("quest/�廢���ŵ�/����", 1);
// �����Ѿ��ò����ı��
	add("dai",-1);
	return 1;
}
