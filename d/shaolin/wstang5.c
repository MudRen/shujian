inherit ROOM;

void create()
{
        set("short", "��ɮ��");
        set("long", @LONG
���������»�����ɮ���估��ס֮�������ڹ�����������ʱ��
����������֮����һ����ǿ��׳����ɮ���Կ���������ѧ֮�ذ¡�
LONG
        );
        set("exits", ([
  "south" : __DIR__"wstang6",
  "north" : __DIR__"wstang4",
  ]));
        set("objects", ([
            CLASS_D("shaolin") + "/wuseng4":1 ]) );
   set("coor/x",-30);
 set("coor/y",240);
   set("coor/z",120);
   setup();
}
