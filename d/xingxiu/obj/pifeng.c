// pifeng.c
// caiji@SJ 8/27/2000 ���ݽ��������޸ģ���о���ͬ�Ļ������æCUT�� 
#include <ansi.h> 
#include <armor.h> 
 
inherit SURCOAT;
 
void create() 
{
	object me=this_object(); 
        set_name( HIB "��������" NOR, ({ "chimei pifeng", "pifeng" }) ); 
        set_weight(300); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ����˵����ɢ��������ʹ�˲�����Ӱ�����硣\n"); 
                set("value", 300);
                set("material", "cloth"); 
                set("wield_msg", "$N��������չ��"+me->name()+"�������ϣ�������������Ʈ�\n");
                set("unwield_msg"," $N��"+me->name()+"���������������˻��\n");
                set("armor_prop/armor", 4); 
                set("armor_prop/dodge", 1); 
              } 
        setup(); 
} 
