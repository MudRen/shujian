// Room: /d/dali/ydxxxxxx.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ϱߵ����Ҳ���ϣ�����ʯѨ������������ǧ��������࣬�ᳲ����ÿ
������֮�䣬ǧ��ֻ���ӽ��붴�ڣ�������Ů�����ܺ����ÿ�꣬���Ƕ�Ҫ��
��Щ�����ϲɼ�Ϊ���ɹ۵����ѣ���Ϊ�̲���Ʒ��
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"west" : __DIR__"ydxxxxx",
	]));

	setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/ydxxxxxx",1);
      }
}
