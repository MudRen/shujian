// Code of ShenZhou 
// weapon: /d/zhongnan/obj/yaochu.c 
// sdong 08/06/98 
        
#include <weapon.h> 
        
inherit HAMMER; 
        
void create() 
{ 
        set_name("ҩ��", ({ "yao chu", "chu" }) ); 
        set_weight(1000); 
        if( clonep() ) 
                set_default_object(__FILE__); 
        else { 
                set("unit", "��"); 
                set("long", "����һ��ȫ��̵���������ר�Ų�ҩ�õ�ҩ���������˶��˵�"
                        "ʹ����Ȼ�����Ѿ��⼣�߰��ˣ����ǳ��ڻ��������ķ������Բ�С�ľ��п�"
                        "�ܰ�ҩ���ڶϡ����������ȫ��·�ϵ����������ɼ�����Ҫ��ҩ�ġ�\n");            
                set("value", 50); 
                set("material", "iron"); 
                set("wield_msg", "$N�ó�һ��$n���������С�\n"); 
                set("unwield_msg", "$N�������е�$n��\n"); 
        } 
       
        init_hammer(5); 
        setup(); 
}        

void init() 
{ 
        object me = this_player(); 
        if ( me->query("id",1)!="qiu chuji" && !wizardp(me)) 
        { 
                set("no_drop",  "��ô���õĶ�����ô�������ء�\n"); 
                set("no_steal", "���������͵������\n"); 
                set("no_get", "��������㲻���á�\n"); 
        } 
} 

