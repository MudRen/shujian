// Room: /dali/zahuopu.c
// bbb 1997/06/12
// Modify By River 98/12/
inherit MISC_ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����һ��СС���ӻ��̣�����С��ȴ��ʰ�÷ǳ����룬��Ϊ�����ǳ���
���˵Ļ��ӵأ��������Ļ��ﶼ���صشӲ��س�;�����ġ���һ��������ģ��
���ں��ϰ��ּۻ��ۡ��������һ������(zhaopai)��
    ��ǰ���˸�����(sign)��
LONG
	);

	set("item_desc", ([
		"zhaopai": "���� \"list\" �г���ǰ�����\"buy\" ���ϰ幺�\n",
	]));
	set("exits", ([
           "north" : __DIR__"nanjie5",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));

	set("coor/x",-290);
  set("coor/y",-470);
   set("coor/z",-20);
   setup(); 
}

void init()
{
	object me = this_player();
     	::init();
     	if(me->query_temp("xuncheng")){
      	me->set_temp("dali_xc/zahuopu",1);
      	}
}
