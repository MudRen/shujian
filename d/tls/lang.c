inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
����һ���ǳ��ľ��ĳ��ȡ�����С·ͨ�����޾������߹�ȥ����
Ժ������֡�
LONG);
     set("exits",([
        "west" : __DIR__"road3",
        "east" : __DIR__"songlin",
    ]));
    set("coor/x",-290);
  set("coor/y",-300);
   set("coor/z",40);
   setup();
}




