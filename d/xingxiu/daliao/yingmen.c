
inherit ROOM;

void create()
{
	set("short", "Ӫ��");
	set("long", @LONG
��ǰ��ԭ�ϳ���һƬ��������������¹��Ѿ�Χ����Ӫկ�����ߴ�������
�ĺŽ�������Զ���и�Ӫ�ţ�һ�Ӷӵ����������������������Ӫ�������Ѿ�ע
�⵽���ˣ�����û��ǸϿ��뿪Ϊ�

LONG
	);
           set("quest",1);
	set("exits", ([
		"north" : __DIR__"zhongying",
		"south" : __DIR__"shanlu3",
	]));
  set("outdoor","����");
  setup();
}
#include "daliao.h";
