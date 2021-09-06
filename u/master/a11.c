// sw_jian.c 松纹古剑
// by Looklove 2000/8/25 for a quest

#include <armor.h>
#include <ansi.h>
inherit EQUIP;



void init()
{
   
    this_object()->armor_init();

 
}
void create()
{
string str;

switch(random(3)){

case(0):         set_name(HIM"紫霞正气靴"NOR,({ "zhengqi xue", "shoes" }) );
set("armor_type","shoes");
set("unit","双");
break;
case(1):         set_name(HIM"紫霞正气甲"NOR,({ "zhengqi jia", "armor" }) );
set("armor_type","armor");
set("unit","件");
break;
case(2):         set_name(HIG"松纹宝盔"NOR,({ "songwen kui", "cap" }) );
set("armor_type","cap");
set("unit","顶");
break;
/*
case(3):         set_name(HIG"松纹古棒"NOR,({ "songwen stick", "songwen bang" }) );
set("skill_type","stick");
break;
case(4):         set_name(HIG"松纹古棍"NOR,({ "songwen gun", "songwen club" }) );
set("skill_type","club");
break;
case(5):         set_name(HIG"松纹古锤"NOR,({ "songwen hammer", "songwen chui" }) );
set("skill_type","hammer");
break;
case(6):         set_name(HIG"松纹古杖"NOR,({ "songwen zhang", "songwen staff" }) );
set("skill_type","staff");
break;
case(7):         set_name(HIG"松纹古钩"NOR,({ "songwen hook", "songwen gou" }) );
set("skill_type","hook");
break;
case(8):         set_name(HIG"松纹古匕"NOR,({ "songwen dagger", "songwen bishou" }) );
set("skill_type","dagger");
break;
case(9):         set_name(HIG"松纹古枪"NOR,({ "songwen spear", "songwen qiang" }) );
set("skill_type","spear");
break;
case(10):         set_name(HIG"松纹古笔"NOR,({ "songwen brush", "songwen bi" }) );
set("skill_type","brush");
break;
case(11):         set_name(HIG"松纹古叉"NOR,({ "songwen fork", "songwen cha" }) );
set("skill_type","fork");
break;
case(12):         set_name(HIG"松纹古斧"NOR,({ "songwen axe", "songwen fu" }) );
set("skill_type","axe");
break;
*/
}
       set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                // set("unit", "件");
                set("material", "cloth");
                set("rigidity", 1);
                set("can_inset",1); // 允许镶嵌
                set("armor_prop/armor", 1);
                set("canwear","华山派");
                set("no_drop","这东西，不能随便丢弃。\n");
set("ke_w/socket",1);
set("ke_w/special_ke2",1);
                set("no_give","这东西给别人，恐怕不好吧？\n");
                set("wear_msg", HIC"$N穿上一件$n"+HIC+"，英姿飒爽。\n"NOR);
               // set("remove_msg", HIC"$N神色自若地将$n"+HIC+"斜挂在腰间。\n"NOR);

        }
        
     
        setup();

}



int long()
{
string line;

line = sprintf("%s(%s)\n",
             query("name"),
             query("id") 
                );
line += sprintf("这是一"+query("unit")+""+query("name")+"，上刻有几个古体篆字：\n");
line +=sprintf(BMAG+HIY"神兵天成，有德者据之: "+query("owner")+"\n"NOR);
line += sprintf("┌─────────────────────┐\n");
line  +=sprintf("│"HIY"适用门派: %-24s        "NOR"│\n",
              query("canwear"),
              );

if (query("haveinsert")) {

if(query("ke_w/max_armor")) 
line +=sprintf("│"HIR"增加防御: %-18s              "NOR"│\n",
              chinese_number(query("level")*50)+"点"
);

if(query("ke_w/max_int")) 
line +=sprintf("│"HIR"增加悟性: %-18s              "NOR"│\n",
              chinese_number(query("level")*2)+"点"
);

if(query("ke_w/max_con")) 
line +=sprintf("│"HIR"增加根骨: %-18s              "NOR"│\n",
              chinese_number(query("level")*2)+"点"
);

if(query("ke_w/max_dex"))
line +=sprintf("│"HIR"增加身法: %-18s              "NOR"│\n",
              chinese_number(query("level")*2)+"点"
);

if(query("ke_w/max_kar")) 
line +=sprintf("│"HIR"增加福缘: %-18s              "NOR"│\n",
              chinese_number(query("level")*2)+"点"
);

if(query("ke_w/max_attribute"))
line +=sprintf("│"HIR"增加所有属性: %-18s          "NOR"│\n",
              chinese_number(query("level"))+"点"
);
}

else

line +=sprintf("│"YEL"还未镶嵌，未有任何效果。                  "NOR"│\n");    
line += sprintf("└─────────────────────┘\n");

    write(line);

}

int wear() 
{
        object me = environment();
        if (living(me) && me->query("family/family_name") !=query("canwear")){
tell_object (me,"你和人家"+query("canwear")+"素无渊源，怎么随便穿人家服饰？\n");
return 0;
        }           
return ::wear();
}


string query_save_file(string arg)
{
        string id;
string type=query("armor_type");
        id = query("owner");
if(arg) type = arg;
        if( !stringp(id) ) return 0;
return sprintf("/data/eq/%c/%s/%s", id[0],id,type);
}

int save()
{
        string file;

if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore(string arg)
{
        string file;

        if( stringp(file = this_object()->query_save_file(arg)) )
                return restore_object(file);
        return 0;
}


