{EPITECH} | First year | Unix System programming project

Vous devez programmer un interpréteur de commandes UNIX. L'interpréteur doit afficher une invite ( $> , par exemple) et attendre que vous écriviez une ligne de commande, qui doit être validée par un retour à la ligne.
L'invite ne doit être réaffichée qu'après l'exécution de la commande. Seules les lignes de commande de base sont censées être exécutées ; pas de tuyaux, de redirections ou d'autres fonctions avancées. Les exécutables doivent être ceux qui se trouvent dans le chemin d'accès, comme indiqué dans la variable PATH.
Si l'exécutable ne peut être trouvé, vous devez afficher un message d'erreur et réafficher l'invite. Les erreurs doivent être traitées et le message approprié doit être affiché sur la sortie d'erreur.
Gérer correctement le PATH et l'environnement (en copiant et en restaurant l'env initial).
Implémenter les builtins suivants : cd, setenv, unsetenv, env, exit.
