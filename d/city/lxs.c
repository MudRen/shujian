// /d/city/lxs.c
// this is made by beyond
// update beyond
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"�����°���"NOR);
	set("long",@long
�������г����θ�̨������Χ�����壬ǰ��С̨��С̨��������������
�ݣ����Ե��ˡ���λ�ڸ�̨���룬��Ϊש������������Ϊ���ǣ�������������
�ӣ�������ʮ�����ݳ���ԲȦ���ơ�ʮ���족�����ϸ�Բ�̣�������ͭ�Ƶĺ�
«������������ש���ɣ�������������֮һ��
long);
	set("exits",([
		"east" : __DIR__"hubian1",
	]));
	set("objects", ([    
"/d/city/npc/laopu" : 1,
	]));

	set("outdoors", "����");
	set("coor/x",80);
  set("coor/y",40);
   set("coor/z",0);
   set("coor/x",80);
  set("coor/y",40);
   set("coor/z",0);
   set("coor/x",80);
  set("coor/y",40);
   set("coor/z",0);
   set("coor/x",80);
  set("coor/y",40);
   set("coor/z",0);
   setup();
}
