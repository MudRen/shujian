
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@long
������Ϊ�������С����׳ơ������롱���ഫ��ʩ�ڴ������ۡ�������
һ��ֱ̫ͨ�����˹������СϪ��
long);
set("outdoors", "suzhou");
set("exits",([
"eastup" : __DIR__"shiyuan",
"southwest" : __DIR__"caixiangjing",
]));
set("coor/x",160);
  set("coor/y",-300);
   set("coor/z",10);
   setup();
}
