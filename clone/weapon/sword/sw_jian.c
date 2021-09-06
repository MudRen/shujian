// sw_jian.c 松纹古剑
// by Looklove 2000/8/25 for a quest

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIG"松纹古剑"NOR,({ "songwen jian", "songwen gujian", "jian","sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("material", "wood");
                set("rigidity", 1);
                set("weapon_prop/parry", 1);
                set("weapon_prop/sword", 1);
                set("no_drop","师傅给的剑，不能随便丢弃。\n");
                set("no_give","师傅的剑给别人，恐怕不好吧？\n");
                set("wield_msg", HIC"$N自腰间抽一把$n"+HIC+"，舞了个剑花。\n"NOR);
                set("unwield_msg", HIC"$N神色自若地将$n"+HIC+"斜挂在腰间。\n"NOR);
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

if( me->query("family/family_name") != "武当派")
                return 0;

new_name = me->query("env/swj");


if(new_name && strlen(new_name) == 6 &&new_name[4..5] == "剑" )  set("name",HBBLU + new_name + NOR);

i = me->query("combat_exp")/ 200000; 

   if (i < 50)  i = 50;
   if (i > 100)  i = 100;
 j = me->query_skill("taiji-jian",1)/ 5;
   if (j < 50)  j = 50;
   if (j > 100)  j = 100;

   ob_desc =
            sprintf("剑上刻着一行小字：武当秘藏,张三丰赠弟子%s(%s)佩用,见此物如见三清世尊。\n",me->query("name"),me->query("id"));
 
set("long",ob_desc);
set("rigidity", 5);
set("weapon_prop/parry", i);
set("weapon_prop/sword", j);
set("owner", me->query("id"));

/*//------------------------------------------------

这里根据玩家的标记来取得装备的标记
这个标记统一以武器或者装备的id来记录
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
