inherit ROOM;

void create()
{
        set("short", "�����䳡-����̨");
        set("long",@LONG
����̨��һ������ƽ̨��������ɮ����ϰ���յĵط���̨��
����ľ׮��÷��׮��ɳ����ɳ���������ʩ�͸���ɮ������������
�����ɮ������һ���໥�д衣
LONG);
        set("outdoors","dali");
        set("exits", ([
               "southdown" : __DIR__"longxiang1",
           
       	]));
set("objects",([
		__DIR__"npc/wuseng1" : 1,
			]));

        set("coor/x",-400);
  set("coor/y",-310);
   set("coor/z",40);
   setup();
}
