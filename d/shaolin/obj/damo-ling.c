// damo-ling.c ��Ħ��

inherit ITEM;

void create()
{
        set_name("��Ħ��", ({"damo ling", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�������������ƣ��ɷ���ǩ����ƾ�˿ɵ���������ʦ����ս��\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "steel");
              set("no_give",1);
      set("no_drop",1);
set("no_steal",1);
set("no_get",1);
        }
}

