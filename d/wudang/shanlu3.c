// xiaolu1.c �ּ�С��
#include <ansi.h>

inherit ROOM;
int do_jiao(string arg);

void create()
{
	set("short", YEL"��ľ��"NOR);
	set("long", @LONG
������һ��ƫƧ��ɽ·�ϣ����ܹ�ľ�Դԣ�����滨��ݣ�����һ�곤��
����(guoshu)��Ϊ��������˼�������·��������Ѱ��ֻ�в�ҩ���˲Ÿҽ�
����ɽ��
LONG
        );
	set("outdoors", "�䵱");

	set("exits", ([
		"west" : __DIR__"shanlu2",
	]));

	set("item_desc", ([
		"guoshu" : "�������ɹ����磬��Ϊ���ڷ����ʧȥ������֦Ҷή�ң����ܿ��������\n"
	]));

	set("jiao_count", 3);
	set("guo_count", 1);
 
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
}

int do_jiao(string arg)
{
	object me;
	object obguo;
	me = this_player();

	if ( !arg || arg != "guoshu" )
		return notify_fail("��Ҫ��ʲô?\n");

	if (! present("xiang cha", me))
		return notify_fail("����ʲô����?!\n");
     
	message_vision(HIG"$Nϸ�ĵذѲ豭���Ů���㽽�ڳ��������ϡ�\n"NOR, me);

	if (present("xiang cha", me))
		destruct(present("xiang cha",me));

	add("jiao_count", -1);
	if (query("jiao_count") > 0) {
		message_vision(HIG"��豻�������գ�֦Ҷ���ø������ˡ�\n"NOR, me);
		return 1;
	}

	obguo = unew(MEDICINE_D("rsg"));

	if(query("guo_count") >= 1 ){
		if( !clonep(obguo)){
			set("jiao_count", 3);
			message_vision(HIG"����Ӫ����������������ֻ�ܿ���һ��������С����\n"NOR, me);
			return 1;
		}
		if( clonep(obguo) && obguo->violate_unique()){
			set("jiao_count", 3);
			message_vision(HIG"����Ӫ����������������ֻ�ܿ���һ��������С����\n"NOR, me);
			destruct(obguo);
			return 1;
		}
		write(HIM"ͻȻ�����м䳤��һ�����٣��漴���������Ͼͽ��һ�������������εĳ�����!\n"NOR);
		message_vision("$NС�������ժ�³��������������˵ش��뻳�С�\n",me);
		obguo->move(me);
		set("jiao_count", 3);
		return 1;
	}
	else {
		set("jiao_count", 3);
		message_vision(HIG"����Ӫ����������������ֻ�ܿ���һ��������С����\n"NOR, me);
	}
	return 1;
}

int count = 20;
void reset()
{
	if (--count == 0) {
		count = 20; 
		set("guo_count", 1); 
		::reset();
	}
}

int clean_up()
{
	return 0;
}
