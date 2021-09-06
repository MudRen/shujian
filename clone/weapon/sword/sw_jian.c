// sw_jian.c ���ƹŽ�
// by Looklove 2000/8/25 for a quest

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG"���ƹŽ�"NOR,({ "songwen jian", "songwen gujian", "jian","sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("rigidity", 1);
                set("weapon_prop/parry", 1);
                set("weapon_prop/sword", 1);
                set("no_drop","ʦ�����Ľ���������㶪����\n");
                set("no_give","ʦ���Ľ������ˣ����²��ðɣ�\n");
                set("wield_msg", HIC"$N�������һ��$n"+HIC+"�����˸�������\n"NOR);
                set("unwield_msg", HIC"$N��ɫ�����ؽ�$n"+HIC+"б�������䡣\n"NOR);
        }
         init_sword(120);
     
        setup();
}



int query_autoload()
{

object me = environment();  
string ob_desc,new_name;         
int i,j;                

if (!me || !interactive(me) || !living(me))   
		return 0;

if( me->query("family/family_name") != "�䵱��")
                return 0;

new_name = me->query("env/swj");


if(new_name && strlen(new_name) == 6 &&new_name[4..5] == "��" )  set("name",HBBLU + new_name + NOR);

i = me->query("combat_exp")/ 200000; 

   if (i < 50)  i = 50;
   if (i > 100)  i = 100;
 j = me->query_skill("taiji-jian",1)/ 5;
   if (j < 50)  j = 50;
   if (j > 100)  j = 100;

   ob_desc =
            sprintf("���Ͽ���һ��С�֣��䵱�ز�,������������%s(%s)����,�����������������\n",me->query("name"),me->query("id"));
 
set("long",ob_desc);
set("rigidity", 5);
set("weapon_prop/parry", i);
set("weapon_prop/sword", j);
set("owner", me->query("id"));

/*//------------------------------------------------

���������ҵı����ȡ��װ���ı��
������ͳһ����������װ����id����¼
*/
if( me->query("songwen gujian"))
{
i = me->query("songwen gujian/cuilian");

set("weapon_prop/damage", i*10 + 220);
set("weapon_prop/attack", i*5 + 50);
set("weapon_prop/dexerity",       i + 3);
set("weapon_prop/constitution",   i + 3);
set("weapon_prop/intelligence",   i + 3);
set("weapon_prop/strength",       i + 3);

}
















//------------------------------------------------

        return 1;

}

void owner_is_killed()
{
        destruct(this_object());
} 
