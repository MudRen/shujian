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
  "south" : __DIR__"wstang4",
  "north" : __DIR__"wstang2",
  ]));
        set("objects", ([
            CLASS_D("shaolin") + "/wuseng2":1 ]) );
               set("coor/x",-30);
  set("coor/y",260);
   set("coor/z",120);
   setup();
}
