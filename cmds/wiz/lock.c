// by darken@SJ

#include <ansi.h>
#include <login.h>
#define SYNTAX "÷∏¡Ó∏Ò Ω£∫lock <ƒ≥»À> because <‘≠“Ú>\n"
#define BLOCK "/d/death/block"

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob, where;
	string name, reason;
 
	if(!str || sscanf(str, "%s because %s", name, reason)!=2 )
		  return notify_fail(SYNTAX);
       
	if (!objectp(ob = LOGIN_D->find_body(name))) 
		  return notify_fail("√ª”–’‚∏ˆ»À∞…?\n");

	if (wiz_level(ob))
		 return notify_fail("◊•Œ◊ ¶£øƒ„“‘Œ™ƒ„ «darken∞°£ø\n");

	if(!objectp(where = environment(ob)))
		  return notify_fail("’‚∏ˆ»À≤ª÷™µ¿∂„‘⁄ƒƒ¿Ô“Æ... :-( \n");
	
	if (ob->query("registered") < 2)
		return notify_fail("’‚∏ˆ»À≤ª «’˝ Ω◊¢≤·µƒÕÊº“°£\n");

	if (file_name(where) == BLOCK)
		  return notify_fail(ob->query("name") + "“—æ≠‘⁄À¿–Ã∑øÀºπ˝¡À£¨≤ª”√‘Ÿ◊•¡À°£\n");

	if (base_name(ob) == "/cmds/leitai/leitaiuser")
		return notify_fail(ob->name() + "’‚»À «±»Œ‰¿ﬁÃ®Clone≥ˆ¿¥µƒ£¨‘⁄¿ﬁÃ®ƒ⁄»√À˚¿Îø™æÕ «¡À°£\n");

	tell_room(where, WHT HBMAG"Õª»ª≥ˆœ÷¡À¡Ω∏ˆπÙ◊” ÷£¨∞—"+ob->query("name")+"º‹µΩÀ¿–Ã∑ø»•¡À°£\n"NOR, ob);
	tell_object(ob, MAG"¡Ω∏ˆπÙ◊” ÷∞—ƒ„Õ∆Ω¯¡ÀÀ¿–Ã∑ø¥....\n"NOR);

	message("shout", YEL HBRED "\n°æºÕ¬…°ø"+ob->query("name")+"("+capitalize(ob->query("id"))
		+")“ÚŒ™£€" + reason + "£›£¨Œ•∑¥ ÈΩ£”Œœ∑πÊ‘Ú£¨æˆ∂®∏¯”ËπÿΩ¯À¿–Ã∑øµƒ¥¶∑£°£\n\n" NOR, users());

	log_file("static/LOCK",
		sprintf("%s(%s) “ÚŒ™ [%s] ±ª %s(%s) ◊•µΩÀ¿–Ã∑ø°£\n",
			ob->query("name"),ob->query("id"), reason, (string)me->query("name"),me->query("id")
		), me, ({ ob })
	);
	ob->delete("enter_wuguan");
	ob->move(BLOCK);
	return 1;
}
