#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
void create()
{
        set_name(HIC"���ޱ���"NOR, ({ "xinxiu bencao", "medicine book" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("treasure",1);
                set("unique", 1);
                set("long", "����һ�����ƴ��վ��ȱ༭��ɵ�ҽѧҩ�䣬���Ƴ�͢��ȫ��������ͨ
ʹ�ã�Ϊ�й�ҽѧʷ�ϵ�һ������ҩ�䣬���ֱ���Ϊ���Ʊ��ݡ���\n");
                 set("value", 45000);
                set("material", "paper");
                set("exp_required", 200000);
                 set("jing_cost", 75);
                set("difficulty", 32);
                set("min_skill", 120);
                set("max_skill", 141);
        }
}
#include "m-book.h";
                
