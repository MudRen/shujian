inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@long
����ɽ�������������¡�������ԭϵ�������޹���ַ��Ϊ������������
�֡�����̾����ڵ�����ʼ�����ϳ���ԭ������¡��ƴ��ĳ������£��ŷ�
���ڡ�
long);
set("objects",([
__DIR__"npc/ke" : 2,
]));
set("exits",([
"northdown" : __DIR__"shiyuan",
"west" : __DIR__"zhonglou",
"east" : __DIR__"lingyanta",
"enter" : __DIR__"dxbdian",
]));
set("coor/x",130);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}
