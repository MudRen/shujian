#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(WHT"��õ��"NOR,({ "rose", "meigui" }) );
        set_weight(500);
        if( clonep() )
        	set_default_object(__FILE__);
        else {                            
        	set("unit","��");
                set("material", "cloth");
          set("value",150);
              set("female_only", 1);
        	set("armor_prop/armor", 1);
            set("long", "����һ����õ��,��׷ҷ�,�����Ŵ���İ��顣\n");
            set("wear_msg", "$N����ժ��һ����ڷ��ޱߣ�"WHT"��õ��"NOR"����Ĵ���͸��,ӳ�ճ�һ���������׵�����\n");
            set("remove_msg", "$Nժ�·��ߵ�"WHT"ˮ��õ��,С������İ����պ�.\n"NOR);
	}
        setup();
}
