// conglinggu.c �����(kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	  set("short", "�����");
	  set("long",@long
�����ǰͻȻΪ֮һ����ֻ��һ����һ��������Ͽ����ʯ�䣬��ɽ��ѩ
ˮк�䵽ǧ�����µ�ɽ����ȥ����������ܵķ�ĭ����һ�־��Ķ��ǵ��𺶡�
��������ɽҰ�ȵ�Ϫ���ߣ�ȴ�����˸��ָ����Ļ�����ľ�����췱������Ͽ��
�����ʵѹ��ɽ�����˼����������������ǵ���԰��
long);

 	  set("exits",([
		"out" : __DIR__"shanlin"+(random(5)+1),
	  ]));

	  set("objects", ([
                 MEDICINE_D("huangqi") :  1,
                 MEDICINE_D("dongchongcao") : 2,
	  ]));

	  setup();
}
