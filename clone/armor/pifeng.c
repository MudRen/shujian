// pifeng.c
 
#include <ansi.h> 
#include <armor.h> 
 
inherit SURCOAT;
 
void create() 
{ 
        set_name( HIR "��������" NOR, ({ "jinhu pifeng", "pifeng" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ���ɺ�ɫ�����磬�����ý�������һͷ����ͻ��������߱ߣ��ǳ�������\n"); 
                set("value", 300); 
                set("material", "cloth"); 
                set("wield_msg", "$N��������չ�����������������ϣ�������������Ʈ�ƽ���˼������硣\n");
                set("unwield_msg"," $N����������������������˻��\n");
                set("armor_prop/armor", 10); 
                set("armor_prop/dodge", 2); 
              } 
        setup(); 
} 
