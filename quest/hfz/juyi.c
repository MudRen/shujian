//�ڷ�կ������

#include <ansi.h>

inherit ROOM;
void create()
{
      set("short", HIY"������"NOR);
      set("long", @LONG
�������կ����ͷ���ѽ���ƽ����������ĵط���ѧ������С˵��
�е�����������������������š���ʵ���Ͽ��½������ֽ��á���Ϊ���ʡ�
LONG);
      set("outdoors","�ڷ�կ");
      set("exits", ([
            "west" : "/quest/hfz/xiaolu2",
      ]));

      setup();
//  replace_program(ROOM);
}
//�Ǿ���
int is_mirror() { return 1; }