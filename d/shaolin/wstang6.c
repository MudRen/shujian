inherit ROOM;

void create()
{
        set("short", "��ɮ��");
        set("long", @LONG
���������»�����ɮ���估��ס֮�������ڹ�����������ʱ��
����������֮����һ����ǿ��׳����ɮ���Կ���������ѧ֮�ذ¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wstang5",
  ]));
        set("objects", ([
            CLASS_D("shaolin") + "/wuseng5":1 ]) );
   set("coor/x",-30);
 set("coor/y",230);
   set("coor/z",120);
   setup();
       }
