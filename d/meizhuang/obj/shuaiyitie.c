inherit ITEM;
#include <ansi.h>
void create()
{
       set_name(HIM"������"NOR, ({ "shuaiyi tie", "tie", "shuaiyi" }) );
       set_weight(100);
       if( clonep() )
               set_default_object(__FILE__);
      else {
               set("unit", "��");
               set("long", WHT @LONG
������Ƴ���������������������ϵĲ���󿪴�
�أ�����һλ���ָ���չ���Ṧ���ܸ߷��ͣ���Ȼ
�ж�Ѹ�ݣ�ȴ��ʧ���ŵķ��¡���βд������ϸ�
�˲���ͼ�£�����������Ƿ�ͬС�ɡ�
LONG NOR);
               set("value", 100000);
               set("no_give",1);
               set("treasure",1);
               set("no_put",1);
               set("no_drop",1);
               set("material", "jade");
       }
       setup();
}

