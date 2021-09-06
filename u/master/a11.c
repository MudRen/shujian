// sw_jian.c ���ƹŽ�
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

case(0):         set_name(HIM"��ϼ����ѥ"NOR,({ "zhengqi xue", "shoes" }) );
set("armor_type","shoes");
set("unit","˫");
break;
case(1):         set_name(HIM"��ϼ������"NOR,({ "zhengqi jia", "armor" }) );
set("armor_type","armor");
set("unit","��");
break;
case(2):         set_name(HIG"���Ʊ���"NOR,({ "songwen kui", "cap" }) );
set("armor_type","cap");
set("unit","��");
break;
/*
case(3):         set_name(HIG"���ƹŰ�"NOR,({ "songwen stick", "songwen bang" }) );
set("skill_type","stick");
break;
case(4):         set_name(HIG"���ƹŹ�"NOR,({ "songwen gun", "songwen club" }) );
set("skill_type","club");
break;
case(5):         set_name(HIG"���ƹŴ�"NOR,({ "songwen hammer", "songwen chui" }) );
set("skill_type","hammer");
break;
case(6):         set_name(HIG"���ƹ���"NOR,({ "songwen zhang", "songwen staff" }) );
set("skill_type","staff");
break;
case(7):         set_name(HIG"���ƹŹ�"NOR,({ "songwen hook", "songwen gou" }) );
set("skill_type","hook");
break;
case(8):         set_name(HIG"���ƹ�ذ"NOR,({ "songwen dagger", "songwen bishou" }) );
set("skill_type","dagger");
break;
case(9):         set_name(HIG"���ƹ�ǹ"NOR,({ "songwen spear", "songwen qiang" }) );
set("skill_type","spear");
break;
case(10):         set_name(HIG"���ƹű�"NOR,({ "songwen brush", "songwen bi" }) );
set("skill_type","brush");
break;
case(11):         set_name(HIG"���ƹŲ�"NOR,({ "songwen fork", "songwen cha" }) );
set("skill_type","fork");
break;
case(12):         set_name(HIG"���ƹŸ�"NOR,({ "songwen axe", "songwen fu" }) );
set("skill_type","axe");
break;
*/
}
       set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                // set("unit", "��");
                set("material", "cloth");
                set("rigidity", 1);
                set("can_inset",1); // ������Ƕ
                set("armor_prop/armor", 1);
                set("canwear","��ɽ��");
                set("no_drop","�ⶫ����������㶪����\n");
set("ke_w/socket",1);
set("ke_w/special_ke2",1);
                set("no_give","�ⶫ�������ˣ����²��ðɣ�\n");
                set("wear_msg", HIC"$N����һ��$n"+HIC+"��Ӣ���ˬ��\n"NOR);
               // set("remove_msg", HIC"$N��ɫ�����ؽ�$n"+HIC+"б�������䡣\n"NOR);

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
line += sprintf("����һ"+query("unit")+""+query("name")+"���Ͽ��м�������׭�֣�\n");
line +=sprintf(BMAG+HIY"�����ɣ��е��߾�֮: "+query("owner")+"\n"NOR);
line += sprintf("����������������������������������������������\n");
line  +=sprintf("��"HIY"��������: %-24s        "NOR"��\n",
              query("canwear"),
              );

if (query("haveinsert")) {

if(query("ke_w/max_armor")) 
line +=sprintf("��"HIR"���ӷ���: %-18s              "NOR"��\n",
              chinese_number(query("level")*50)+"��"
);

if(query("ke_w/max_int")) 
line +=sprintf("��"HIR"��������: %-18s              "NOR"��\n",
              chinese_number(query("level")*2)+"��"
);

if(query("ke_w/max_con")) 
line +=sprintf("��"HIR"���Ӹ���: %-18s              "NOR"��\n",
              chinese_number(query("level")*2)+"��"
);

if(query("ke_w/max_dex"))
line +=sprintf("��"HIR"������: %-18s              "NOR"��\n",
              chinese_number(query("level")*2)+"��"
);

if(query("ke_w/max_kar")) 
line +=sprintf("��"HIR"���Ӹ�Ե: %-18s              "NOR"��\n",
              chinese_number(query("level")*2)+"��"
);

if(query("ke_w/max_attribute"))
line +=sprintf("��"HIR"������������: %-18s          "NOR"��\n",
              chinese_number(query("level"))+"��"
);
}

else

line +=sprintf("��"YEL"��δ��Ƕ��δ���κ�Ч����                  "NOR"��\n");    
line += sprintf("����������������������������������������������\n");

    write(line);

}

int wear() 
{
        object me = environment();
        if (living(me) && me->query("family/family_name") !=query("canwear")){
tell_object (me,"����˼�"+query("canwear")+"����ԨԴ����ô��㴩�˼ҷ��Σ�\n");
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


