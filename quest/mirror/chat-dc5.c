inherit ROOM;

void create()
{
  set ("short", "���귿");
  set ("long", @LONG

һ����ɫ���ο�̴�㿿���������������ܷ���һȦ�����ž۾������
���ˡ��м���һ��ʯ�����������һ����������̴��̨��һλ����
���ݵĹ�ͯ��Χ�Ź�̨ת��תȥ���귿��ǽ�Ϲ�������(paizi)��

LONG);

  set("item_desc",([
    "paizi" : "Ѻ���ٹ꣺ sai cs <amount> <money>\n"+ 
              "Ѻǧ��꣺ sai qn <amount> <money>\n"+ 
              "Ѻ���Ϲ꣺ sai bl <amount> <money>\n", 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"chat-dc4",
  ]));
  setup();
}
//�Ǿ���
int is_mirror() { return 1; }