//�ڷ�կɽկ����

#include <ansi.h>

inherit ROOM;
void create()
{
set("short", "ɽկ��");
      set("long", @LONG
������Ǳ�������ɽկ���ڷ�կ���ˡ�ͷ�����կ�ӵĴ��ţ���կ
�����ආ�������ȥ��Ѳ�ߡ���կ���ﲻʱ����һ�����Ұ�Ľк�����
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
            "northup" : "/quest/hfz/guangchang",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }
