// letter
#include <ansi.h>

inherit ITEM;

void init();

void create()
{
        set_name(HIW"��������"NOR,({"xin", "shu xin", "letter" }));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������ڵ��ż㣬��������ݹ�������ת����һλ���ѵġ�
����
                 ���ָ�"+HIR"����"+NOR"����"+HIC"��ɽ"+NOR"�ٰݡ�
\n�㿴���ŷ�����Ϥ�����飬���ɵû������ڵ���������е����ġ�\n\n");
                set("unit", "��");
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("value", 0);                
         }
}
int query_autoload()
{
	return 1;
}
