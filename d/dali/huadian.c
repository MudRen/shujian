// Room: /dali/huadian.c
// bbb 1997/06/11
// Modify By River 98/12/	  
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��һ�����������һ��������ֻ���ӷ��������棬ȫ�ǻ��������
ǩ��д��:����ױ�ع���,��ʮ��ѧʿ��,���۶��ġ�,���糾������֮�࣬��
�ֶ��Ǵ���Ĺ������軨�������Ĺ���������˽�����æӭ��������
LONG
	);
	set("exits", ([
           "west" : __DIR__"dongjie7",
        ]));

	set("objects", ([
	       __DIR__"npc/maihua": 1,
	       __DIR__"npc/yatou": 1,
        ]) );
	set("coor/x",-280);
  set("coor/y",-450);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/huadian",1);
      }
}
